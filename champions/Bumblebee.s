.name "Bumblebee"
.comment "Defensive state"

begin:
#load the prog number in arg of live
sti r1, %:live, %1
fork %:live
ld %120, r4
ld %0, r2
fork %:live
zjmp %:attack

live:
#say live via a forked process
live %2
ldi %:live, %1, r1
ld %30, r2
zjmp %:live

attack:
#the goal is to attack different zone of memory
#replicating him and forking at the new pos
ld %40, r6
zjmp %:attack