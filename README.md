
# Cloning and Building

```
west init -m https://github.com/tonyarkles/nanopb-demo.git nanopb-demo-workspace
cd nanopb-demo-workspace
west update
cd nanopb-demo
west build -b qemu_x86
west build -t run

Ctrl-a x to quit QEMU
```


