# Swap Two Integers

```
{X, Y of type integers}
X := X + Y
Y := X - Y
X := X - Y
{X=Y; Y=X; X, Y of type integers}
```

## Proof via Weakest Precondition:

=> { X=Y; Y=X; X, Y of type integers }

`X := X - Y`

=> { X=Y; Y=X-Y; X, Y of type integers }

`Y := X - Y`

=> { X=X-Y; Y=X-(X-Y); X, Y of type integers }

=> { X=X-Y; Y=Y; X, Y of type integers }

`X := X + Y`

=> { X=(X+Y)-Y; Y=Y; X, Y of type integers }

=> { X=X; Y=Y; X, Y of type integers }
(q.e.d)
