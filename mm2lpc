#!/usr/bin/tclsh

package require json

array set arguments {-t default.template.c -d area -p prefix_ -m map.m2w}
array set arguments $::argv

set areaPath $arguments(-d)
set roomPrefix $arguments(-p)
set mapFile $arguments(-m)
set templateFile $arguments(-t)


proc exitsByIndex {ndx mapPaths} {
    set x {}
    foreach i $mapPaths {
        if {[lindex $i 1] == $ndx} {
            lappend x [lindex $i 3]
        }
    }
    return $x
}

proc exitToCoord {x y e} {
    set coor {}
    switch $e {
        s {
            lappend coor [expr {$x }]
            lappend coor [expr {$y - 1}]
        }
        n {
            lappend coor [expr {$x }]
            lappend coor [expr {$y + 1}]
        }
        e {
            lappend coor [expr {$x + 1}]
            lappend coor [expr {$y}]
        }
        w {
            lappend coor [expr {$x +1 }]
            lappend coor [expr {$y}]
        }
        nw {
            lappend coor [expr {$x - 1}]
            lappend coor [expr {$y + 1}]
        }
        ne {
            lappend coor [expr {$x - 1}]
            lappend coor [expr {$y + 1}]
        }
        sw {
            lappend coor [expr {$x - 1}]
            lappend coor [expr {$y - 1}]
        }
        se {
            lappend coor [expr {$x - 1}]
            lappend coor [expr {$y - 1}]
        }
    }
    return $coor
}

proc exitToName {ext} {
    switch $ext {
        s {
            return south
        }
        n {
            return north
        }
        e {
            return east
        }
        w {
            return west
        }
        nw {
            return northwest
        }
        ne {
            return northeast
        }
        sw {
            return southwest
        }
        se {
            return southeast
        }
    }
}

proc coordToFileName {x y} {
    return [format "%s%.3d_%s%.3d"\
                [expr { $x < 0 ? "n" : "p" }] [expr { abs($x) }]\
                [expr { $y < 0 ? "n" : "p" }] [expr { abs($y) }]]
}


set fp [open $mapFile]
set mapData [read $fp]
close $fp

set mapData [::json::json2dict $mapData]

set mapRooms [dict get $mapData places]
set mapPaths [dict get $mapData paths]



set tmp {}
foreach i $mapPaths {
    lappend tmp [lindex $i 0]
    lappend tmp [lindex $i 1]
}
set mapPaths $tmp
unset tmp

set fp [open $templateFile]
set templateData [read $fp]
close $fp

file mkdir $areaPath

foreach i $mapRooms {
    array set tmp $i

    set fn [coordToFileName $tmp(y) $tmp(x)]
    set fp [open "${areaPath}/${roomPrefix}${fn}.c" w+]

    set exits [exitsByIndex $tmp(id) $mapPaths]
    set exitString ""
    foreach j $exits {
        set coord [exitToCoord $tmp(x) $tmp(y) $j]
        set exitString "$exitString\"[exitToName $j]\":\"${roomPrefix}[coordToFileName [lindex $coord 0] [lindex $coord 1]]\",\n"
    }
    puts $fp [string map [list //_EXITS $exitString] $templateData]

    close $fp
}
