function [g] = la_euklid01(m,n)
% Funktionsbaustein zur Berechnung des 
% groessten gemeinsamen Teilers von m 
% und n mit dem euklidischen Algorithmus

% Annahme: m >= n > 0
%%% Initialisierung 

r0 = m; 
r1 = n; 
% berechne den Rest der ganzzahligen Division 
r = mod(r0,r1); 
% solange dieser Rest nicht verschwindet, fuehre weitere 
% Division mit Rest durch 
while r ~= 0 
    r0 = r1; 
    r1 = r; 
    r  = mod(r0,r1); 
end
% der ggT ist der letzte nichtverschwindende Rest
g = r1;
end

