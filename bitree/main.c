#include "bitree.h"

void main(int argc, const char* argv[])
{
	bitree_t *root = NULL;
	root = create_binary_tree(1);
	printf("create is successful!\n");

	printf("pre_order : ");
	// pre_order(root);
	pre_order1(root);
	printf("\n");
	printf("in_order : ");
	// in_order(root);
	in_order1(root);
	printf("\n");
	printf("post_order : ");
	// post_order(root);
	post_order1(root);
	printf("\n");
}
