
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/workqueue.h>
#include <asm/io.h>


#define NAME "intertkekan.c"

static struct workqueue_struct *mqueue;

irq_handler_t irqhandler(int irq, void *dev_id, struct pt_regs *regs)
{
    return (irq_handler_t)IRQ_HANDLED;
}

static int key_init_module(void)
{
  int retval;
  printk("keyboard module initialised\n");
  mqueue = create_workqueue(NAME);
  retval = request_irq(1,(irq_handler_t)irqhandler, IRQF_SHARED, "kbd", (void *)(irqhandler));
  printk("request IRQ 1 : %d",retval);
  return retval;
}

static void key_cleanup_module(void)
{
  free_irq(1, (void *)irqhandler);
}

MODULE_LICENSE("GPL");
module_init(key_init_module)
module_exit(key_cleanup_module)
