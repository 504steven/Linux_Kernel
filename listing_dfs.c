#include <linux/module.h>			
#include <linux/sched.h>	
// dont have to be static function
//__init and __exit are also Macro

void helper(struct task_struct *process){
	struct task_struct *next_process;
	struct list_head *list; 
	printk(KERN_INFO "%-6d%-17s%-1ld", process->pid, process->comm, process->state);
	list_for_each(list, &process->children) {
		next_process = list_entry(list, struct task_struct, sibling);
		helper(next_process);	
	}	
}

static int __init listing_dfs_init(void)
{
	printk(KERN_INFO "listing_DFS_module loaded\n");
	printk(KERN_INFO "P-ID  Name            State");
	helper(&init_task);
	return 0;
}

static void __exit listing_dfs_exit(void)
{
	printk(KERN_INFO "listing_DFS_module un-loaded\n");
}

module_init(listing_dfs_init);
module_exit(listing_dfs_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Listing Linux Kernel Module DFS");
MODULE_AUTHOR("WGC");