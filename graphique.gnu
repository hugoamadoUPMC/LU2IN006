set xlabel "Taille de n"
set ylabel "Temps (s)"
set title "Comparaison des temps de recherche entre liste chaînée et table de hachage"
plot "graphique.txt" using 1:2 with lines title "Liste chaînée", \
     "graphique.txt" using 1:3 with lines title "Table de hachage"
set terminal png
set output "graphique.png"
replot
