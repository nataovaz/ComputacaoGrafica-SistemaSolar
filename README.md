# ComputaçãoGráfica - SistemaSolar
Este projeto foi criado com a ideia de criar um Sistema Solar com as funcionalidades do OpenGl, através da disciplina de Computação Gráfica e Processamento de Imagens, desenvolvido por alunos de Engenharia de Computação - UNIFEI.

https://github.com/nataovaz/ComputacaoGrafica-SistemaSolar/blob/main/LICENSE

## Desenvolvido por
- Natan - Engenharia da Computação [Github](https://github.com/nataovaz)
- Brenda - Engenharia da Computação [Github](https://github.com/BrendaGobira)

### Ideia fundamental do projeto
Para dar início ao projeto, em primeiro momento, montamos um cena com vários
objetos utilizando todas as funções primitivas de criação dos sólidos, como mostra a imagem
abaixo. No entanto, com o intuito de elaborar mais o projeto, foi levantada a ideia de criar um
Sistema Solar com as funcionalidades do OpenGl, incrementando nele alguns objetos
incomuns, como um cubo, um bule de chá e um icosaedro.

### Etapas do projeto
Nos Arquivos de Origem do projeto, é possível encontrar, além do arquivo
Origem.cpp — onde está a base do código do trabalho —, os outros arquivos importantes
para o funcionamento do programa. Nele, estão presentes os Bitmaps necessários para as
texturizações dos modelos; o bmpLoader.h e bmpLoader.c, que são responsáveis por
percorrer os arquivos de bitmap das imagens; o texture.h e o texture.cpp geram as funções,
onde os arquivos serão passados, possibilitando seu uso como textura; o primitiva.h armazena
as funções dos modelos usados e; por último, foi inserido um README.txt com as
informações dos discentes e para instruir o usuário de como observar todos os modelos
renderizados pelo código.

Neste sentido, o arquivo primitiva.h é aquele que vai retornar todas as funções que
elaboram as figuras tridimensionais, como um cubo, um bule de chá e um icosaedro. A
elaboração desta biblioteca é bastante importante para a indentação do projeto. Os arquivos
de textura com a extensão “.bmp” são aqueles que irão texturizar os mapeamentos dos
sólidos.
Ademais, as fontes de iluminação utilizadas na elaboração do Sistema Solar foram a
pontual, ambiente, difusa e especular. Elas foram declaradas na função display, presentes na
Origem.cpp.

#### Anexos:
![Image](https://i.imgur.com/FaKxCAt.jpg "Projeto finalizado")
