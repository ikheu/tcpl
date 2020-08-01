#include <stdio.h>

typedef long Align; /* for alignment to long boundary */

union header {		/* block header: */
	struct {
		union header *ptr;	/* next block if on free list */
		unsigned size;		/* size of this block */
	} s;
	Align x;		/* force alignment of blocks */
};

typedef union header Header;


static Header base;		/* empty list to get started */
static Header *freep = NULL;	/* start of free list */

/* malloc: general-purpose storage allocator */
void *malloc_(unsigned nbytes)
{
	Header *p, *prevp; // p 遍历中的当前节点；prevp 前一个节点
	Header *morecore(unsigned);
	unsigned nunits;

	nunits = (nbytes+sizeof(Header)-1) / sizeof(Header) + 1;
	if ((prevp = freep) == NULL) {	/* 尚未分配过 */
		base.s.ptr = freep = prevp = &base;
		base.s.size = 0;
	}
	for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
		if (p->s.size >= nunits) {	/* big enough */
			if (p->s.size == nunits)	/* 正好匹配上 */
				prevp->s.ptr = p->s.ptr;
			else {			/* 在尾部进行分配 */
				p->s.size -= nunits;
				p += p->s.size;
				p->s.size = nunits;
			}
			freep = prevp;
			return (void *)(p+1);
		}
		if (p == freep)		/* wrapped around free list */
			if ((p = morecore(nunits)) == NULL) // 系统调用，分配内存
				return NULL;	/* none left */
	}
}

/* free: put block ap in free list */
void free_(void *ap)
{
	Header *bp, *p;

	bp = (Header *)ap - 1;
	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr) { // 不在两个连续的节点之间就继续遍历
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {  // 到达链表末尾并且要释放的位置在链表尾部或头部
            break;
        }
    }
	if (bp + bp->s.size == p->s.ptr) {
		bp->s.size += p->s.ptr->s.size;
		bp->s.ptr = p->s.ptr->s.ptr;
	} else {
        bp->s.ptr = p->s.ptr;
    }
	
	if (p + p->s.size == bp) {
		p->s.size += bp->s.size;
		p->s.ptr = bp->s.ptr;
	} else {
        p->s.ptr = bp;
    }
	freep = p;
}

#define NALLOC 1024	/* minimum units to request */

/* morecore: ask system for more memory */
Header *morecore(unsigned nu)
{
	char *cp, *sbrk(int);
	Header *up;

	if (nu < NALLOC)
		nu = NALLOC;
	cp = sbrk(nu * sizeof(Header));
	if (cp == (char *) - 1)	/* no space at all */
		return NULL;
	up = (Header *) cp;
	up->s.size = nu;
	free_((void *)(up+1));
	return freep;
}




int main() {
    int t;
    int *p = malloc_(sizeof(int));
    *p = 123;
    int *p1 = malloc_(sizeof(int));
    int *p2 = malloc_(sizeof(int));
    int *p3 = malloc_(sizeof(int));
    free_(p2);
    free_(p);
    printf("%d\n", freep->s.size);
    
    // t = (((Header *)p) - 1)->s.size;
    // printf("%d\n", t);
    // t = (((Header *)p1) - 1)->s.size;
    // printf("%d\n", t);
    // t = (((Header *)p2) - 1)->s.size;
    // printf("%d\n", t);
    // printf("%d\n", freep->s.size);
    // printf("%d\n", freep->s.ptr->s.size);
    // printf("%d\n", freep->s.ptr->s.size);
    // printf("%d\n", freep->s.ptr->s.size);
}
