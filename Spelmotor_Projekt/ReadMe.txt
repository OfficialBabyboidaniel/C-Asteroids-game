Beskrivning:

Detta är ett spel som utspelar sig i rymden, du som spelare ska skjuta sönder asteroiderna som håller på att flyga mot dig, de dödar dig ifall du blir träffad.
Till din hjälp kan du röra dig med A och D eller Höger och Vänster pil, på detta sätt kan du undvika asteroiderna.
Du kan såklart också skjuta sönder asteroiderna med din pistol, pistolen avfyrar ett skott när du trycker ner musknappen.
Om du blir träffad dör du och därmed är spelet över.  

Instruktion för att bygga och testa spelet:

Öppna en integrerad terminal med hjälp av makefile, skriv make som första command (detta kompilerar spelet), sedan skriv ./build/debug/play för att köra spelet.  
Sökvägar har definierats i constants.h filen som har gåtts igenom via olika filstrukurs föreläsningar. Alla resurser kan hittas i “resources” Mappen.
 Exempel till en sökväg där jag sätter en bild till en textur:
 texture = IMG_LoadTexture(sys.get_ren(), (constants::gResPath + "images/beams.png").c_str()); 
