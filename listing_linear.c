#include <linux/module.h>	/* Needed by all modules */
#include <linux/sched.h>	/* Nedded for the for_each_process() macro*/

/*
char comm[TASK_COMM_LEN];
pid_t pid;
volatile long state;
struct list_head children;
struct list_head sibling;
*/

static int __init listing_linear_init(void)
{
	printk(KERN_INFO "LinearListing Module is launched\n");
	struct task_struct *task;
	printk(KERN_INFO "Process Name      PID State");
	for_each_process(task) {
		/* on each iteration task points to the next task */
		printk(KERN_INFO "%-15s%6d%6ld", task->comm, task->pid, task->state); 		
	}
	return 0;
}

static void __exit listing_linear_exit(void)
{
	printk(KERN_INFO "LinearListing Module is removed\n");
}

module_init(listing_linear_init);
module_exit(listing_linear_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Listing Linux Kernel Module Linearly by PId");
MODULE_AUTHOR("Gaochao/Lu");