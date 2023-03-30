# RayTracingToy
Pràctica 1 - GiVD 2022-23

En aquest fitxer cal que feu l'informe de la pràctica 1.

## Equip:
**B07**
* Oscar De Caralt Roy
* Alejandro Guzman Requena
* Adrià Alfonso Medero
* Noah Márquez Vara

### Features (marqueu les que heu fet i qui les ha fet)
- Fase 0
    - [✅] Background amb degradat
      - Oscar + Adrià (Reviewed by: Noah & Alejandro)
    - [✅] Color Shading
      - Noah (Reviewed by: Alejandro, Oscar & Adrià)
    - [✅] Normal Shading
      - Alejandro (Reviewed by: Noah, Adrià & Oscar)
    - [✅] Depth Shading
      - Adrià, Oscar & Alejandro (Reviewed by: Noah)
    - [✅] Intersecció amb l'escena
      - Noah (Reviewed by: Alejandro, Oscar & Adrià)
 - Fase 1
    - Creació de nous objectes i interseccions (VIRTUALWORLD) 
        - [✅] Hit Box
          - Alejandro + Noah (Reviewed by: Adrià & Oscar)
        - [✅] Hit Triangle
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Hit Malla
          - Oscar + Adrià + Noah (Reviewed by: Alejandro)
        - [✅] Bounding Box Malla
          - Oscar + Adrià + Alejandro (Reviewed by: Noah)
        - [✅] Bounding Sphere Malla
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
    - Creació de REAL DATA
        - [✅] FITTED PLANE: Pla de terra
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Transformacions Translació i Escalat amb gizmos esferes
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Gizmo de Box
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Noves dades
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
  - Fase 2
    - Pas 1. Abans de començar la Fase 2
        - [✅] Solucionar l'aliasing
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Aplicar Gamma Correction
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
    - Pas 2. Implementació dels diferents shadings
        - [✅] Blinn-Phong Shading
          - Alejandro & Oscar & Noah & Adrià
        - [✅] Phong Shading
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
        - [✅] Cel Shading
          - Noah (Reviewed by: Alejandro, Oscar & Adrià)
    - Pas 3. Afegir ombres
        - [✅] Blinn-Phong Shadow
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
        - [✅] Phong Shadow
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
        - [✅] Color Shadow
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
        - [✅] Normal Shadow
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
        - [✅] Cel Shadow
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
        - [✅] Escena més complexa
          - Alejandro (Reviewed by: Noah, Oscar & Adrià)
     - Pas 4. Afegir recursió al mètode RayPixel
        - [✅] Material metal + rajos reflectits
          - Adrià & Noah (Reviewed by: Alejandro & Oscar)        

- Parts opcionals: 
  - [✅] Cilindres
    - Noah (Reviewed by: Alejandro, Oscar & Adrià)
  - [ ] Escena CSG 
  
  - [ ] Més d'una propietat en les dades reals
   
  - [ ] Mapeig de les dades reals en una esfera
  
    
### Explicació de la pràctica    
  * **Organització de la pràctica**
    * Durant el nostre projecte de gràfics i visualització de dades, hem estat treballant de forma eficient i organitzada. Una de les nostres principals    estratègies ha estat dividir la feina entre els membres del grup, designant les tasques a fer a ClickUp i utilitzar la plataforma GitHub per compartir/revisar el nostre treball. Això ens ha permès mantenir-nos al dia amb els diferents aspectes del projecte i donar feedback als companys per a millorar i corregir errors. A més, també hem tingut una comunicació constant i efectiva entre nosaltres, utilitzant un xat per estar en contacte tots els dies. Això ha estat clau per a resoldre els dubtes i les preocupacions que han anat sorgint durant el desenvolupament del projecte, i per a prendre decisions de forma conjunta. 
Hem seguit una dinàmica de treball excel·lent, creant branques individuals per al nostre treball i fusionant-les només quan estàvem segurs que tot funcionava bé. Això ha evitat errors i malentesos i ha garantit que el nostre treball fos coherent i consistent en tot moment.
En resum, la nostra organització ha estat força bona, gràcies a la nostra dedicació i esforç conjunt, estem satisfets de la nostra feina.
  
  * **Decisions a destacar**
    * El nostre projecte va implicar la col·laboració de tots membres del grup, i per aconseguir completar-lo amb èxit, vam haver de prendre diverses decisions importants. Una d'aquestes decisions va ser utilitzar una eina de gestió de projectes com ClickUp. A través d'aquesta plataforma, vam poder mantenir un seguiment de les tasques que cada membre del grup havia de realitzar, així com de les dates límit per a la seva finalització. No obstant, el nostre projecte també va experimentar alguns imprevistos que vam haver de solucionar. En concret, dos membres del grup van experimentar problemes tècnics amb el Qt Creator. Per aquesta raó, van haver de treballar presencialment durant una setmana i mitja a les aules, fins que finalment van aconseguir solucionar el problema. És important destacar que, malgrat els imprevistos que vam haver de solucionar durant el nostre projecte, en general, va transcórrer sense problemes greus. Això significa que no vam haver de prendre decisions arriscades o molt compromeses per garantir la seva finalització. En general, vam aprendre la importància de la planificació adequada, la comunicació i la cooperació per aconseguir els objectius que ens havíem proposat.
  
  * **Preguntes a respondre (totes les fases)**
    * FASE 0
    * FASE 1
        * 3a. Quan penses que és millor crear els triangles de la malla?
            * Per aconseguir crear els triangles adequats per la creació de la malla, la funció maketriangles() s'haurà de cridar seguidament d'haver llegit el fitxer amb load(), així, un cop ja tenim la informació d'arestes i vertex, podem começar a generar els triangles en bucle.
        * 3b. Quina creus que teòricament és millor? Com funcionen en la realitat?
            * Una bounding sphere és una esfera que envolta un objecte 3D. Aquesta esfera es calcula a partir dels punts extrems de l'objecte, i té un radi que permet determinar la distància màxima entre el centre de l'esfera i qualsevol punt de l'objecte. De forma similar, una bounding box és un cub que envolta un objecte 3D i al igual que la bounding box ens ajuda a fer molt més eficaç un sistema de col·lisions. Quina és millor? En resum, depén del objecte 3D. La bounding sphere és millor utilitzada en situacions on els objectes són esfèrics o quasi-esfèrics, ja que ofereix una representació més senzilla i fàcil de calcular per a la detecció de col·lisions. D'altra banda, la bounding box és més eficaç en situacions on els objectes són rectangulars, ja que ofereix una representació més precisa de l'espai ocupat per l'objecte. En molts casos, es pot utilitzar una combinació de les dues tècniques per obtenir una detecció de col·lisions més precisa i eficient en escenes 3D complexes.
    * FASE 2
        * 1.2. On afegiries un atribut numSamples que defineixi el nombre de rajos per píxel i així controlar aquest fet?
            * Aquest atribut es definirà a la classe Setup.hh
        * 2.3. Què necessites canviar?
        * 2.4. Necessites afegir informació en el material?
        * 3.2. En el cas que hi hagi un objecte entre la llum i el punt on s'està calculant la il·luminació, quina component de la fórmula de Blinn-Phong s'haurà de tenir en compte?
        * 4.3. Per què si tens el MAX_DEPTH a 1, l’esfera no es veu transparent?
            * Si hi ha materials transparents a l'escena, com ara vidres o superfícies d'aigua, aquests materials requereixen que els raigs es reflecteixin i refractin a través de la seva superfície per reproduir adequadament el seu aspecte visual. Però si la profunditat de seguiment de raigs està limitada a 1, els raigs que travessen aquests materials transparents no tindran suficient profunditat per calcular correctament la seva trajectòria, i per tant, aquests materials transparents no es mostraran correctament a la pantalla.
        * 4.3. Si assignes el color ambient global enlloc del de background en els rajos secundaris que no intersequen amb res. Com et canvia la visualització? Raona el per què?
            * Assignar el color ambient global en lloc del color de fons en els raigs secundaris que no intersequen amb cap objecte tindria com a conseqüència que aquests raigs que no intercepten cap objecte, tindrien un color ambient uniforme en lloc d'un color de fons o background. Això podria canviar la visualització, depenent de l'escena en qüestió.

    * FASE 3
        * Qui calcularà les coordenades (u, v) del punt d’intersecció amb el pla?
        * Com faries el càlcul de les penombres?


### Screenshots de cada fase
* **Fase 0**: 
    - Background amb degradat:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221958233-e1d4bcdb-23bb-4fcf-a511-369e302b3d86.png" alt="Background amb degradat" width="45%">
    </p>

    - Color Shading:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221958361-d3091823-5032-49d4-914a-ad36a31261c1.png" alt="Color Shading" width="45%">
    </p>

    - Normal Shading:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221958503-21b42fcd-b882-40bb-8b63-c62a2ffdcea3.png" alt="Normal Shading" width="45%">
    </p>

    - Depth Shading:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221958612-c048ac76-1860-4ed9-8852-8bbd48b6ba00.png" alt="Depth Shading" width="45%">
    </p>

    - Intersecció amb l'escena:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221958704-c6ca7cc7-905c-451d-a740-915f8f36131d.png" alt="Intersecció amb l'escena 1" width="45%">
     <img src="https://user-images.githubusercontent.com/47271218/221958771-edb7d5f7-938e-4ed0-b60f-65d339f2c8aa.png" alt="Intersecció amb l'escena 2" width="45%">
    </p>

    - Apartat (m) --> Fitxer .json amb més esferes:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/221971858-210c0063-c5d1-4870-af7e-5e5d67dfc15d.png" alt="Depth Shading" width="45%">
    </p>


* **Fase 1**: 
Creació de nous objectes i interseccions (VIRTUALWORLD):
    - Hit Box:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225356939-2f105b69-60ba-42be-932c-e91e7f570248.png" alt="Hit Box" width="45%">
    </p>
    
    - Hit Triangle:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/224562781-9bcfbe5a-7f4b-492c-ac51-e4111786c3f4.png" alt="Hit Triangle" width="45%">
    </p>
    
    - Hit Mesh:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225109807-a1d36b94-88f0-41d5-9eb8-3e6e7215e410.png" alt="Hit Mesh" width="45%">
    </p>
    
    - Bounding Box & Bounding Sphere:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225279162-3210322c-a20e-41c0-8f28-ebc8bb6999a7.png" alt="Bounding Box" width="45%">
     <img src="https://user-images.githubusercontent.com/47271218/225279307-dd3316db-a0af-4ce5-9c47-acef0d8eb1e5.png" alt="Bounding Sphere" width="45%">
    </p>


Creació de REAL DATA:

- Fitted Plane & Transformacions (Translació i Escalat amb gizmos esferes):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225163352-b813e93e-e98c-47c8-bd73-d05727760105.png" alt="FittedPlane & Gyzmo Sphere" width="45%">
    </p>
  
- Gizmo de Box:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225357133-9d220940-2203-487a-90dd-fec9dcc8efa0.png" alt="Gyzmo Box" width="45%">
    </p>

- Noves dades:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/225280337-75948158-caf4-4962-8a87-17cfb9233474.png" alt="Noves Dades" width="45%">
    </p>
    
* **Opcionals**:
Fase 1:
    - Hit Cilindre:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/224562896-ef66aff3-31af-4436-82c7-8d04bf7d23f2.png" alt="Hit Cilindre" width="45%">
    </p>
    
    
* **Fase 2**: 
Pas 1. Abans de començar la Fase 2:

- Aliasing (BEFORE):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226004637-653efb17-54eb-4ecc-91d7-bf0e9e800adb.png" alt="Aliasing before" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226004989-f80dfe51-3897-4a73-95c6-da697d3683dc.png" alt="Aliasing before (zoom)" width="45%">
    </p>


- Aliasing (AFTER):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226005206-3f0b4f10-9e6e-40f7-83cf-b1d1f24f8f8c.png" alt="Aliasing after" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226005763-caa344db-2c4b-4f79-a571-b8c304f9f9f9.png" alt="Aliasing after (zoom)" width="45%">
    </p>


- Gamma Correction:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226005206-3f0b4f10-9e6e-40f7-83cf-b1d1f24f8f8c.png" alt="Gamma Correction" width="45%">
    </p>
    
Pas 2. Implementació dels diferents shadings:

- Blinn-Phong Shading:

    a. Només component ambient
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171631-fa26adaf-36ad-4c2a-b870-eab2e09e6967.png" alt="Component ambient" width="45%">
    </p>
    
    b. Només component difosa
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171640-b79b1244-4649-4490-932e-1cb0879e0ed4.png" alt="Component difosa" width="45%">
    </p>
    
    c. Només component especular
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171660-1e67634a-aa8c-41bd-9837-b1527310f756.png" alt="Component especular" width="45%">
    </p>
    
    d. Les tres juntes
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171669-74b66a44-58e9-421c-8ddc-bfaa3957efaa.png" alt="Les tres components" width="45%">
    </p>
    
    e. Afegint atenuació amb profunditat
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171678-5499d916-5be5-4e8a-822e-90000247e597.png" alt="Atenuació amb profunditat" width="45%">
    </p>
    
    f. Afegint ambient global
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171686-de5b7df7-b7ab-4d90-8bc3-c8432c069430.png" alt="Ambient global" width="45%">
    </p>
    
- Phong Shading:

    a. Només component ambient
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171799-c1853834-6e41-4f9a-910a-3051960c84e2.png" alt="Component ambient" width="45%">
    </p>
    
    b. Només component difosa
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171819-4b9f652b-b0bc-45c6-9245-bf9468cc3791.png" alt="Component difosa" width="45%">
    </p>
    
    c. Només component especular
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171835-abbd26f6-db5d-4d6d-a88c-d7c9c5e50d6c.png" alt="Component especular" width="45%">
    </p>
    
    d. Les tres juntes
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171855-fc13407c-0c1f-4a6e-afc9-23610685a457.png" alt="Les tres components" width="45%">
    </p>
    
    e. Afegint atenuació amb profunditat
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171874-faede113-ce06-437d-940f-fbe1d4a2c7c6.png" alt="Atenuació amb profunditat" width="45%">
    </p>
    
    f. Afegint ambient global
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171891-5a366c40-21e7-41c4-9724-c2d5e781df7d.png" alt="Ambient global" width="45%">
    </p>
    
- Cel Shading:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226171985-8fe5c426-6ce9-45b1-a045-edfe460bed79.png" alt="Cel (Toon) Shading" width="45%">
    </p>
    
    
Pas 3. Afegir ombres:

- Blinn-Phong Shadow:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226172095-4b4662c0-cee0-41ef-bfaa-494829a2a615.png" alt="Blinn-Phong Shadow 1" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226172123-5281bca7-c9a7-4498-a673-38ea3bc655b8.png" alt="Blinn-Phong Shadow 2" width="45%">
    </p>

- Color Shadow:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226470091-5c9373fd-a771-4c57-bf64-8c927de1280c.png" alt="Color Shadow 1" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226470095-ad54b2fc-8dd1-4f50-975b-6ff10a210a08.png" alt="Color Shadow 2" width="45%">
    </p>
    
- Normal Shadow:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226470291-e410bf3f-13bc-4d33-99b3-f32d44f45463.png" alt="Normal Shadow 1" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226470300-9db61d80-63f7-4f10-8ecc-65551e0c121f.png" alt="Normal Shadow 2" width="45%">
    </p>
    
- Phong Shadow:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226470517-58d79bb0-8a57-4ba9-ad49-c2fcbc87071f.png" alt="Phong Shadow 1" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226470551-e1146e71-5dca-497f-811f-3fe038d7003f.png" alt="Phong Shadow 2" width="45%">
    </p>
      
 - Cell Shadow:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/226470675-2bbb795a-3c4a-4695-96af-58416c3660f7.png" alt="Cell Shadow 1" width="45%">
    <img src="https://user-images.githubusercontent.com/47271218/226470686-661df6d4-bd27-4f1a-b933-a2534b39e8f4.png" alt="Cell Shadow 2" width="45%">
    </p>
    
    
Pas 4. Afegir recursió al mètode RayPixel:

- Material metal + rajos reflectits (maxdepth=1, maxdepth=3, maxdepth=10):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/227644498-6e383ac4-7e7e-4368-b876-55be57714e69.png" alt="Metal (maxdepth=1)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227644509-cdcc36df-dcb3-4b26-ba64-9b8205803d4f.png" alt="Metal (maxdepth=3)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227644520-7fdc13d6-32f7-41b4-b13a-b38e5f544d74.png" alt="Metal (maxdepth=10)" width="25%">
    </p>
    
- Altres tipus de shading per veure d'altres efectes en les reflexions (color shading, normal shading, phong shading, cell shading; maxdepth=10):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/227645090-752debc8-d239-4621-8658-00e1121e8796.png" alt="Color metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645209-a3ed8a19-c759-4f90-9deb-9b98ca02b485.png" alt="Normal metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645265-de776caf-9527-4afe-98f6-06df052c173d.png" alt="Phong metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645338-cf974249-bd48-4979-9e2e-3e99f89456d3.png" alt="Cell metal (maxdepth=10)" width="25%">
    </p>

* **Més visualitzacions**:



   * Per totes les imatges, incluiu aqui la imatge obtinguda i els fitxers de dades i de configuració que heu fet servir
