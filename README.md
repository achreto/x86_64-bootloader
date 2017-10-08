# A bootloader for x86_64 Systems

This project provides a multiboot based bootstrap code for x86_64 systems. The
bootloader can be used for the bootstrap cores as well as application cores 
of multi-core systems. This is a standalone version of Barrelfish's new x86_64
bootloader.

## License
See the LICENSE file in the repository.

## Authors
See the AUTHORS file in the repository.

## Compilation

```
    make
```

## Running

You should be able to run the boot loader on any machine booting GRUB or also 
within QEMU virtual machine using. 

```
    make runqemu
```
