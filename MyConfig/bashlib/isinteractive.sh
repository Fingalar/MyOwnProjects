# Test for a terminal!

fd=0   # stdin

#  As we recall, the -t test option checks whether the stdin, [ -t 0 ],
#+ or stdout, [ -t 1 ], in a given script is running in a terminal.
if [ -t "$fd" ]
then
echo interactive
else
echo non-interactive
fi


#  But, as John points out:
#    if [ -t 0 ] works ... when you're logged in locally
#    but fails when you invoke the command remotely via ssh.
#    So for a true test you also have to test for a socket.

if [[ -t "$fd" || -p /dev/stdin ]]
then
echo interactive
else
echo non-interactive
fi
