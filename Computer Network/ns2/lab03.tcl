set ns [new Simulator]

$ns rtproto DV

set tracefile [open out.tr w]
$ns trace-all $tracefile

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {
    global ns tracefile nf
    $ns flush-trace
    close $tracefile
    close $nf
    exec nam out.nam &
    exit
}

# make nodes
for {set i 0} {$i<7} {incr i} {
    set n($i) [$ns node]
}

# connections
for {set i 0} {$i<7} {incr i} {
    $ns duplex-link $n($i) $n([expr ($i+1)%7]) 5Mb 10ms DropTail
}


# node n0
set tcp0 [new Agent/TCP]
$ns attach-agent $n(0) $tcp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $tcp0

#node n3
set tcpsink0 [new Agent/TCPSink]
$ns attach-agent $n(3) $tcpsink0

$ns connect $tcp0 $tcpsink0

$ns at 0.5 "$cbr0 start"
$ns rtmodel-at 1.0 down $n(1)
$ns rtmodel-at 2.0 up $n(1)
$ns at 3.0 "finish"

$ns run
