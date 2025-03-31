# Projeto de Jogo - Guia de Desenvolvimento

## Estrutura e Melhorias

### Correções e Melhorias Gerais

- **Corrigir movimentação e animação**
- **Refatorar construtor e destrutor**
  - Aplicar o conceito **RAII (Resource Acquisition Is Initialization)**
  - Trocar `INIT` e `CLEAN` por construtores e destrutores adequados

### Padrões de Projeto

- **Singleton**
  - **O Singleton deve ser aplicado no GameLoop, não no GameWorld.**
  - Explicação: O GameWorld deve focar apenas na lógica do jogo, sem gerenciar inicialização.

### Organização do Código

- **GameWorld**
  - Responsável **apenas** pela lógica do jogo
  - **Não** deve gerenciar lógica de inicialização
- **Math Library**
  - Deixar a biblioteca inteira disponível
- **Remover duplicatas**
  - Unificar elementos duplicados em `persona` e `slime`, movendo para `object`
- **Reorganização de variáveis e macros**
  - `macros.h` e `Math` devem ser movidos para `my-lib`
- **Gerenciamento de Recursos**
  - `SoundManager.h` e `TextureManager`
    - **Evitar salvar em mapas**, pois isso afeta a eficiência da busca
- **Namespaces**
  - Começar a utilizar namespaces para organização do código

### Estrutura de Dados

- **Sistema de Áudio**
  ```cpp
  struct AudioDescriptor {
  };

  struct AudioDescriptor_SDL : public AudioDescriptor {
  };
  ```
- **Pontos Flutuantes**
  - Usar `float` para altura e largura de objetos

### Modularização

- **Criar um módulo exclusivo para colisão**