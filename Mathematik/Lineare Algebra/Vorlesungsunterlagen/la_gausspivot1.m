r = r+1; 
a = abs(A(r,r)); i = r; j = r; 
for o = r:m
    for p = r:n
        if abs(A(o,p)) > a 
            a = abs(A(o,p)); 
            i = o; 
            j = p;
        end
    end
end