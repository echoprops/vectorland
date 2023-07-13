# vectorland
linguagem vetorial de qualidade duvidosa que é REPL, fiz quando vi a quinta aula de C++

observações:
projeto incompleto, não funciona algumas coisas (o set não funciona, exports não funciona, iterate, add-to-vector, revove-to-vector), o processo de parsing é meio - pobre por depender de espacos e eu não corrigi erros que podem acontecer com abuso dos mesmos e pelo parser ser ruim não suporta strings com expressões que tenham espaços
- não pretendo completar ele, estou estudando para criar um novo e melhor que tenha um parser/lexxer melhor com outra sintaxe etc
- não tem editline para histórico etc
- não lembro das demais coisas

como compilar:
``g++ vectorland.cpp -o vetorland -Werror -Wall -Wfatal-errors -Wextra -std=c++17``

ou flags com otimização seguras sem loop unrroling agressivo:

``g++ virgulate.cpp -o virgulate -O2 -Wall -Werror -Wfatal-errors -Wextra -std=c++17 -march=native``

Em flto coloque o numero de threads do seu processador

flags seguras mais agressivas + lto + outras coisas:
``g++ vectorland.cpp -o vectorland -O2 -fpeel-loops -fpredictive-commoning -fsplit-paths -fipa-pta -flto=4 -ftree-loop-distribution -ftree-vectorize -fno-semantic-interposition -fno-common -fno-plt``

flags seguras mais agressivas + secure fast math + lto + outras coisas:
``g++ vectorland.cpp -o vectorland -O2 -fpeel-loops -fpredictive-commoning -fsplit-paths -fipa-pta -flto=4 -ftree-loop-distribution  -ftree-vectorize -fno-semantic-interposition -fno-common -fno-plt -march=native -fno-math-errno -fno-trapping-math``

flags seguras anteriores + sanitizer:
``g++ vectorland.cpp -o vectorland -O2 -fpeel-loops -fpredictive-commoning -fsplit-paths -fipa-pta -flto=4 -ftree-loop-distribution  -ftree-vectorize -fno-semantic-interposition -fno-common -fno-plt -march=native -fno-math-errno -fno-trapping-math -fstack-protector -fsanitize=address,undefined``

sanitizer pode deixar o programa mais lento.

![image](https://github.com/iodaemon/vectorland/assets/95192021/9a84d526-e856-43f1-9847-582b0d1a51ad)

