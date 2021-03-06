BEGIN {

  FS = ":"
  printf "\n           Name    Length     Range"
  printf "     Speed    Weight\n"

}

{
  if ($2 > longest) {
    saved["longest"] = $0
    longest = $2
  }

  if ($3 > heaviest) {
    saved["heaviest"] = $0
    heaviest = $3
  }

  if ($4 > longest_range) {
    saved["longest_range"] = $0
    longest_range = $4
  }

  if ($5 > fastest) {
    saved["fastest"] = $0
    fastest = $5
  }
}

END {

  printf "----------------  --------  --------"
  printf "  --------  --------\n"

  split( saved["longest"], var, ":")
  printf "%15s  %8d  %8d  %8d  %8d (Longest)\n\n", 
         var[1], var[2], var[4], var[5], var[3] 
  delete saved["longest"]

  split( saved["heaviest"], var, ":")
  printf "%15s  %8d  %8d  %8d  %8d (Heaviest)\n\n", 
         var[1], var[2], var[4], var[5], var[3] 

  split( saved["longest_range"], var, ":")
  printf "%15s  %8d  %8d  %8d  %8d (Longest Range)\n\n", 
         var[1], var[2], var[4], var[5], var[3] 

  split( saved["fastest"], var, ":")
  printf "%15s  %8d  %8d  %8d  %8d (Fastest)\n\n", 
         var[1], var[2], var[4], var[5], var[3] 

}
