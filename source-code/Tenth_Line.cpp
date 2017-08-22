# tail -n+10 file.txt | head -1
# awk 'NR == 10' file.txt
awk 'FNR == 10 {print}' file.txt