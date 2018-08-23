# Building LAMMPS

Check out the LAMMPS repository and use the CMake based build system

```
git clone git@github.com:lammps/lammps.git
cd lammps
mkdir build && cd build
cmake ../cmake -DBUILD_LIB=yes -DPKG_GRANULAR=yes -DWITH_JPEG=no
make -j 8
make install
```

Adjust the `-j 8` argument to the number of available CPU cores for building.

This builds LAMMPS as a library and installs it (`sudo` may be required on your
system for the install step). The LAMMPS cmake build system will install a
pkg-config file `liblammps.pc` (into `/usr/local/lib/pkgconfig/liblammps.pc/` by
default). Make sure this path is listed in the `PKG_CONFIG_PATH` environment
variable.
