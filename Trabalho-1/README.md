# Trabalho 1 - Rasterização
  
A atividade tem como finalidade a implementação de três funções PutPixel, DrawLine, DrawTriangle, para realizar a rasterição de 
pontos e linhas em um framework que simula uma memória de vídeo.

//imagem0

## PutPixel

Essa função consiste em colocar uma cor específica, através do sistema de cores RGBA, então eu criei uma classe color para salvar
o valor de cada uma dessas cores ,em um único pixel na tela. Assim essa função recebe como parâmetro a coordenada (x,y) do pixel,
variando entre 0 e IMAGE_WIDTH em ambas as coordenadas e também a sua cor no formato (R,G,B,A) com  sua cores podendo varias entre
0 e 255. Dessa forma, utilzei o array FBptr para colocar a cor escolhida nesse determinado ponto, cada pixel é dividido em
4 bytes, cada um desses bytes tem um cor do sistema RGBA, então para colocar um ponto no pixel (x,y) eu calculei seu offset
através da formula (x*4 + y*4*IMAGE_WIDTH), cada um deles é multiplicado por 4 por causa da quantidade de bytes por pixel e o y 
é multiplicado por IMAGE_WIDTH para fazer com q ele desça uma linha inteira, da seguinte forma :

//imagem1

E esse foi o resultado:

//imagem2
```c++
for(int i = 0; i < IMAGE_WIDTH; i += 5){
		PutPixel(i, i, color(255, 255, 255, 255));
	}
```


## DrawLine

Esse função foi implementada para colocar varios pontos entre dois pontos especificos, dessa forma formando uma linha. Contudo, 
essa função foi a mais complicada das três funções. Primeiramente eu utilizei o algoritimo (simplificado) de Bresenham para 
calcular quais pixels chamar a função PuPixel para colocar entre dois pontos, porém o algoritimo só funcionava para um octante,
no caso o 8º no plano cartesiano, dessa forma eu utilizei de alguma condições e também da função Troca para inverter o valor das
coordenadas, fazendo-o funcionar para todos os oito octantes.

1º- Verificar se a variação do eixo y (dy) é maior do que a do eixo x (dx), se esse for o caso entao eu inverto as coordenadas
    de x pelas coordenadas de y, assim eu salvo um booleano em true para depois inverte-los de volta na hora de usar a função 
    PutPixel.
    
2º- Depois verifiquei se a variação de x (dx) é negativa, se ela fosse inverte a as coordenadas de inicio pela do fim, e também
    inverte a cor do inicio com a cor do final da linha. E também verifica se a variação de y (dy) é negativa, caso seja inverte
    o seu dy para o positivo e salva um booleano em true para usa-lo para decrementar ou incrementar a coordenada y.
    
3º- Finalmente, eu utilizei o booleans salvos para saber se eu deveria decrementar ou incrementar a coordenada y e se eu deveria
    inverter a coordenada x de votla para o y e vice-versa na hora de usar a função PutPixel.
    
 //imagem4 e imagem5

## Obs.: Interpolação de Cores

Dentro do código da função DrawLine eu implementei um código para interpolar a cor entre o ponto inicial e o ponto final da linha.
Sendo assim eu calculei a diferença entre o R, G, B e dividi essa diferença pela variação de x, fazendo assim essas variações 
aumentarem ou diminuirem linearmente com o meu while.

//imagem6

Assim eu consegui fazer linhas interpolando a cor para os oito octantes.

//imagem7
```c++
  DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, 0, 0, color(255, 0, 0, 255), color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH/2, 0, color(255, 0, 0, 255),
				color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH, 0, color(255, 0, 0, 255),
				color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH, IMAGE_WIDTH/2, color(255, 0, 0, 255),
        color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH, IMAGE_WIDTH, color(255, 0, 0, 255),
				color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH/2, IMAGE_WIDTH, color(255, 0, 0, 255),
        color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, 0, IMAGE_WIDTH, color(255, 0, 0, 255), 
				color(0, 0, 255, 0));
	DrawLine(IMAGE_WIDTH/2, IMAGE_WIDTH/2, 0, IMAGE_WIDTH/2, color(255, 0, 0, 255), 
				color(0, 0, 255, 0));
```

## DrawTriangle

Dentre as três funções essa foi a mais simples, pois só é necessário usar 3 coordenadas difrentes e 3 cores no parâmetro e então
desenhar as linhas entre esses 3 pontos usando a função DrawLine, na qual ja está implementada para os oito octantes e com inter
polação de cores

//imagem9
```c++
DrawTriangle(245, 54, color(255, 0, 0, 255), 231, 450, color(0, 255, 0, 255), 62, 70,
					color(0, 0, 255, 255));
```
