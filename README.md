Mudmap2 to lpc converter
========================

This tool converts visual maps made in
 [mud mapper 2](https://github.com/Neop/mudmap2)
into area dir based on a given template.

Requirements
------------

To use this script you'll need tcl and tcllib (for ::json)

Ms windows users will probably find
 [ActiveTCL](https://www.activestate.com/products/tcl/)
(all included) or IronTCL with tcllib as a suitable option to run this script.

Usage
-----

*nix:

    ./mm2lpc.tcl -t template.file.c -d dir/to/write/area/files -p rooms_filename_prefix -m mudmap2.file.m2w

Default options are listed in the scripts head. Adjust path to tcl in
shebang line.

Windows (ActiveTCL): drop ``mm2lpc.tcl`` into directory with
``default.template.c``, ``map.m2w``, then double click the script.

Screenshots
-----------

MM2 map:
![Mudmap2](mm.png)

Dir structure:
![LPCareadir](lpc.png)
