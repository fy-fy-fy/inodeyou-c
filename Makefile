all:
	gcc -Wall inodeyou.c inodelinkedlist.c tsk_inode.c fs_inode.c -ltsk -o inodeyou
clean:
	rm inodeyou
	