cmd_/root/script/lkm_test/lkm.ko := ld -r -m elf_x86_64 -T /usr/src/kernels/3.10.0-327.36.3.el7.x86_64/scripts/module-common.lds --build-id  -o /root/script/lkm_test/lkm.ko /root/script/lkm_test/lkm.o /root/script/lkm_test/lkm.mod.o
