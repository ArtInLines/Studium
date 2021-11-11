# Minimum

```
{ Z1, Z2 sind Zahlen vom Typ integer }
if Z1<Z2 then MIN:=Z1 else MIN:=Z2
{ MIN = min(Z1,Z2) }
```

Der oben beschriebene Algorithmus ist korrekt, weil

1.

```
{ Z1<Z2 }
MIN:=Z1
{ MIN = min(Z1,Z2) }
```

und 2.

```
{ Z1>=Z2 }
MIN:=Z2
{ MIN = min(Z1,Z2) }
```

korrekt sind
