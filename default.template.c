#include <std.h>

inherit ROOM;

void create(){
    object ob;
    ::create();

    set_property("light", 1);
    set_property("indoors",1);
    set_property("no starve",1);

    set_short("Awesome room");
    set_long(query_short() + "
This room is way too awesome.");
    set_smell("default", "It smells awesome.");
    set_listen("default", "In listens awesome.");

    set_exits(([
    //_EXITS
                   ]));

}
