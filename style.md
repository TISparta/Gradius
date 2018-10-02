## Pequeño estilo a seguir:

1. Poner tab como 2 espacios en tu editor (se vera feo sino cuando lo subas
   a github)
2. Class names: PascalCase
3. Function names, variables names: camelCase
4. Indentention style: [K & R style - Variant: Stroustrup](https://en.wikipedia.org/wiki/Indentation_style#Variant:_Stroustrup)
5. Entre llamados a estructuras de repeticion, de control, operadores,
   parentesis, asignacion, definicion de funcion (donde veas necesario)
   poner 1 espacio. Por ejemplo:
   
```c++
  void foo () { return 1; }

  void myFunction (int a, int b) {
    for (int i = a; i <= b; i++) {
      if (a % 2 == 0) foo();
    }
  }

```

6. Si una linea es muy ancha separarla a criterio propio
7. [Be a ninja coder!](https://javascript.info/ninja-code) 
