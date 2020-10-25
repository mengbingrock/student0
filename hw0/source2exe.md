Generate recurse.S and find which instruction(s) corresponds to the recursive call of recur(i - 1).


        subl    $1, %eax
        subl    $12, %esp
        pushl   %eax
        call    recur
        addl    $16, %esp




Here the first number is the symbol's value (sometimes refered to as its address). The next field is actually a set of characters and spaces indicating the flag bits that are set on the symbol. These characters are described below. Next is the section with which the symbol is associated or *ABS* if the section is absolute (ie not connected with any section), or *UND* if the section is referenced in the file being dumped, but not defined there.

"l"
"g"

"u"

"!"

The symbol is a local (l), global (g), unique global (u), neither global nor local (a space) or both global and local (!)

"w"

The symbol is weak (w) or strong (a space).

"C"

The symbol denotes a constructor (C) or an ordinary symbol (a space).

"W"

The symbol is a warning (W) or a normal symbol (a space). A warning symbol's name is a message to be displayed if the symbol following the warning symbol is ever referenced.

"I"

"i"

The symbol is an indirect reference to another symbol (I), a function to be evaluated during reloc processing (i) or a normal symbol (a space).

"d"

"D"

The symbol is a debugging symbol (d) or a dynamic symbol (D) or a normal symbol (a space).

"F"

"f"

"O"

The symbol is the name of a function (F) or a file (f) or an object (O) or just a normal symbol (a space).
