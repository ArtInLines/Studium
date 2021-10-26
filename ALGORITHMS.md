# Algorithmen

## ggT - größter gemeinsamer Teiler
```JS
function ggT(a, b) {
    let h; 
    if (a === 0) return b;
    if (b === 0) return a;
    do {
        h = a % b; 
        // console.log(a + ' = ' + Math.floor(a / b) + ' * ' + b + ' + ' + h);
        a = b;
        b = h;
    } while(b != 0)
    return a; 
}
```
