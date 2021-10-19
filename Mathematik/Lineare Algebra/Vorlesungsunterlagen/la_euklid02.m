function [g,a,b] = la_euklid02(m,n)
% Funktionsbaustein zur Berechnung des 
% groessten gemeinsamen Teilers von m und n
% mit dem euklidischen Algorithmus und einer 
% Darstellung g = a*m + b*n mit ganzen Zahlen a,b,

% Annahme: m >= n > 0
%%% Initialisierung 
r0 = m; 
r1 = n; 
%%% Initialisierung der Koeffizienten der Darstellung
a0 = 1; b0 = 0;
a1 = 0; b1 = 1;

% berechne das Ergebnis der ganzzahligen Division 
r = mod(r0,r1);
q = (r0-r)/r1;      % Ergebnis ist ganzzahlig
% solange dieser Rest nicht verschwindet, fuehre weitere 
% Division mit Rest durch 
while r ~= 0 
    % aktualisiere die Koeffizienten der Darstellung
    c0 = a0 - q*a1;     % zwischenspeichern
    c1 = b0 - q*b1;
    a0 = a1;
    b0 = b1;
    a1 = c0;
    b1 = c1;
    % fuehre neue Division mit Rest durch
    r0 = r1; 
    r1 = r; 
    r  = mod(r0,r1); 
    q  = (r0-r)/r1;
end
% der ggT ist der letzte nichtverschwindende Rest
g = r1;
% Darstellung ist die Darstellung von r1
a = a1;
b = b1;
end

