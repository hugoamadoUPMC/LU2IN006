set xlabel "Taille de n"
set ylabel "Temps (s)"
set title "Comparaison des temps de recherche entre liste chainee et table de hachage"
plot "graphique.txt" using 1:2 with lines title "Liste chainee", \
     "graphique.txt" using 1:3 with lines title "Table de hachage" 
