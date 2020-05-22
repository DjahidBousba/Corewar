.name "zork"
.comment "just a basic living program"

l2:
sti r1,%:live,456789
and r1,%-6,r1
live: live %1
zjmp %:live
