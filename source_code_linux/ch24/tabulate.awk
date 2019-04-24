BEGIN {

  FS = ":"
  printf "\n           Name    Length     Range"
  printf "     Speed    Weight\n"

}

{
  printf "%15s  %8d  %8d  %8d  %8d\n", $1, $2, $4, $5, $3

  len += $2
  wt  += $3
  rng += $4
  spd += $5

}

END {

  printf "\n         Totals   --------  --------"
  printf "  --------  --------\n"
  printf "                 %8d  %8d  %8d  %8d\n\n", 
         len, rng, spd, wt

}
