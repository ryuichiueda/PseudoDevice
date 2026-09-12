#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xf64ac983, "__copy_overflow" },
	{ 0x5cb46e6d, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_from_user" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x1f55c5b2, "kstrtoll" },
	{ 0xdd6830c7, "sprintf" },
	{ 0x9479a1e8, "strnlen" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0x90a48d82, "__ubsan_handle_out_of_bounds" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xb5214c4c, "__register_chrdev" },
	{ 0x52b15b3b, "__unregister_chrdev" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0x5af09d8b, "_raw_spin_lock" },
	{ 0x5af09d8b, "_raw_spin_unlock" },
	{ 0xe9196a28, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0xf64ac983,
	0x5cb46e6d,
	0xa61fd7aa,
	0x092a35a2,
	0xbd03ed67,
	0x1f55c5b2,
	0xdd6830c7,
	0x9479a1e8,
	0xe54e0a6b,
	0x092a35a2,
	0x90a48d82,
	0xd272d446,
	0xb5214c4c,
	0x52b15b3b,
	0xd272d446,
	0xe8213e80,
	0x5af09d8b,
	0x5af09d8b,
	0xe9196a28,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__x86_return_thunk\0"
	"__copy_overflow\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"_copy_from_user\0"
	"__ref_stack_chk_guard\0"
	"kstrtoll\0"
	"sprintf\0"
	"strnlen\0"
	"__fortify_panic\0"
	"_copy_to_user\0"
	"__ubsan_handle_out_of_bounds\0"
	"__stack_chk_fail\0"
	"__register_chrdev\0"
	"__unregister_chrdev\0"
	"__fentry__\0"
	"_printk\0"
	"_raw_spin_lock\0"
	"_raw_spin_unlock\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "95D02CDFCBDA003F343A14A");
