# RayTracingToy
Pràctica 1 (RAYTRACING) - GiVD 2022-23

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
        - [✅] Material transparent + rajos reflectits 
          - Oscar & Noah (Reviewed by: Alejandro & Adrià)
     - Pas 5. Visualization Mapping
        - [✅] Diferents escenes i fitxers
        - Noah (Reviewed by: Alejandro, Oscar & Adrià)
   - Fase 3
     - Pas 1. Afegeix un nou material
        - [✅] Alejandro (Reviewed by: Noah, Oscar & Adrià)
     - Pas 2. Prova amb diferents jocs de dades i mapes
        - [✅] Alejandro (Reviewed by: Noah, Oscar & Adrià)
     - Pas 3. Genera diferents jocs de dades i mapes
        - [✅] Alejandro (Reviewed by: Noah, Oscar & Adrià)
- Parts opcionals: 
  - [✅] Cilindres
    - Noah (Reviewed by: Alejandro, Oscar & Adrià)
  
### Explicació de la pràctica    
  * **Organització de la pràctica**
    * Durant aquest primer projecte de Gràfics i Visualització de Dades, hem estat treballant de forma eficient i organitzada. Una de les nostres principals estratègies ha estat dividir la feina entre els membres del grup, designant les tasques a fer a ClickUp (aplicació externa) i utilitzar la plataforma GitHub per compartir/revisar el nostre treball. Això ens ha permès mantenir-nos al dia amb els diferents aspectes del projecte i donar feedback als companys per a millorar i corregir errors. A més, també hem tingut una comunicació constant i efectiva entre nosaltres, utilitzant un xat per estar en contacte tots els dies. Això ha estat clau per a resoldre els dubtes i les preocupacions que han anat sorgint durant el desenvolupament del projecte, i per a prendre decisions de forma conjunta. 
Hem seguit una dinàmica de treball excel·lent, creant branques individuals per al nostre treball i fusionant-les només quan estàvem segurs que tot funcionava bé. Això ha evitat errors i malentesos i ha garantit que el nostre treball fos coherent i consistent en tot moment.
En resum, la nostra organització ha estat força bona, gràcies a la nostra dedicació i esforç conjunt, estem satisfets de la nostra feina.
  
  * **Decisions a destacar**
    * El nostre projecte va implicar la col·laboració de tots membres del grup, i per aconseguir completar-lo amb èxit, vam haver de prendre diverses decisions importants. Una d'aquestes decisions va ser utilitzar una eina de gestió de projectes com ClickUp. A través d'aquesta plataforma, vam poder mantenir un seguiment de les tasques que cada membre del grup havia de realitzar, així com de les dates límit per a la seva finalització. No obstant, el nostre projecte també va experimentar alguns imprevistos que vam haver de solucionar. En concret, dos membres del grup van experimentar problemes tècnics amb el Qt Creator. Per aquesta raó, van haver de treballar presencialment durant una setmana i mitja a les aules, fins que finalment van aconseguir solucionar el problema. És important destacar que, malgrat els imprevistos que vam haver de solucionar durant el nostre projecte, en general, va transcórrer sense problemes greus. Això significa que no vam haver de prendre decisions arriscades o molt compromeses per garantir la seva finalització. En general, vam aprendre la importància de la planificació adequada, la comunicació i la cooperació per aconseguir els objectius que ens havíem proposat.
    
    * Cal destacar que el codi sembla no utilitzar la memòria correctament en certes ocasions, en les que el programa pot arribat a fer un crash, en aquesta situació només s'ha de reiniciar el Qt Creator i ja funciona correctament.
    
    * Tots els fitxers utilitzats són els presents al campus. A més, hem generat fitxers extres com 'dades_Murcia.json' (fase 3), 'meshExample.json' (fase 1), 'threeSpheres.json' (fase 2), entre d'altres.
  
  * **Preguntes a respondre (totes les fases)**
    * FASE 0
        * 3b. Explora el codi fent una primera execució usant el debugger (o navegant pels mètodes) i veient com des del botó de Trace, s’arriba al mètode run() de la classe RayTracing. Quina escena es té carregada? Qui la crea? Quin setup té la classe? Des d’on es crea?
            * La classe RayTracer carrega la escena i el setup a través del Controller del programa. La classe RayTracer fa una crida al Controlador per obtenir la instància del setup i la instància de l'escena a través dels mètodes getSetUp() i getScene(). La classe Controller té una escena carregada, que pot ser creada a través dels diferents mètodes, i del setup de visualització, que es pot crear amb el mètode createSettings i es guarda en l'atribut visualSetup.
            
        * 3c. Si prems els botó de Trace, es veu el degradat de la figura 2. Per què es veu aquest degradat? A quin mètode es calcula aquest color?
            * Es veu perquè no hem creat res encara i és el que surt per defecte. Es calcula al mètode RayPixel de la classe RayTracer.
            
        * 3d. Si desactives el flag de background, i tornes a fer Trace, quin efecte et trobes? Per què? Pots veure com ha arribat el flag de background al teu RayTracer?
            * Si desactivem el flag de background i torno a fer el Trace, el que succeirà és que en lloc de veure un degradat de colors com a fons, veurem un fons negre. Això és així perquè el fons de degradat es calcula en el mètode RayPixel de la classe RayTracer quan el raig no intersecta amb cap objecte de l'escena, és a dir, quan no es produeix cap col·lisió. Si desactivem el flag de background, llavors aquest degradat no es calcula i la funció RayPixel retorna el color negre.
            
        * 3e. Amb el flag de background activat, intenta fer que el fons es canviï segons es mostra a la figura 3, tenint en compte que es vol un degradat segons les Y’s de forma que es vol pintar de color més blanc quan estigui més avall de les Y's de pantalla (RGB = (1.0, 1.0, 1.0)) i més blavós quan estiguis més amunt (per exemple, RGB = (0.5, 0.7, 1.0)). Fes-ho primer directament en el codi i després intenta veure com llegir els colors que pots posar a la interfície. En quina variable els trobes?
            * Els trobes a la variable shared_ptr<SetUp> setup. 
            
        * 3f. I si volguessis canviar els colors del degradat? On els canviaries?
            * En el mètode RayPixel, amb la variable setup pots obtenir un degradat de 2 colors qualsevols aplicant la següent fòrmula:
float t = 0.5f*(ray2.y+1);
color = vec3((1-t) * setup->getDownBackground()+ t * setup->getTopBackground());

        * 3g. Canvia ara per a que el color es calculi des del ColorShading, es a dir, enlloc de pintar l’esfera amb el color del seu material Kd, es vol usar el càlcul fet a la classe ColorShading. Fixa’t que des del Menu Shadings pots activar aquesta estratègia però cal que la usis en calcular el color de sortida de cada píxel. Com hi pots accedir? A quina variable pots aconseguir l’estratègia a cridar? Com es crea aquesta estratègia des del menú? Resegueix el codi des del MainWindow.
            * 1- a la mainWindow.cpp es fa: QObject::connect(ui->actionColor_Shading, SIGNAL(triggered()), builder, SLOT(activaColorShading())); 
            2- al Builder.cpp es fa activaColorShading() que farà el següent: Controller::getInstance()->createShading(ShadingFactory::SHADING_TYPES::COLOR) 
            3- això ens derivarà a la classe ShadingFactory.cpp on es farà un switch de SHADING_TYPES i si triem fer color (ColorShading) es farà el següent: s= make_shared<ColorShading>();
            
        * 3i. Canvia per a que ara per a que l'esfera es vegi segons els colors de les normals calculades en els punts d'intersecció, i així veuràs aquesta figura. Com faràs per a crear una nova estratègia de shading?
            * A la classe Builder.hh declares que a la classe Builder.cpp crearàs un mètode que es digui activaNormalShading que sigui igual al d'ActivaColorShading() però canviant a SHADING_TYPES::NORMAL. Crees una nova classe anomenada NormalShading amb el seu header i tot (que contindrà constructor, un mètode anomenat shading que retorni un vec3 i un destructor). La funció shading rep com a paràmetres l'objecte scene que conté els objectes de la escena, la informació de l'objecte que s'ha impactat (info) i la posició de la càmera (lookFrom). Shading() calcula la normalització de la normal de l'objecte impactat (N) i, a continuació, crea un color que consisteix en la combinació de la normalització i un vector unitat amb els valors 1, que es corresponen a un color mig gris. Així, el resultat és una escala de grisos que indica la direcció de la normal de l'objecte. A més a més a ShadingFactory hauràs de crear uns altres else if's que s'adaptin a aquest shading:
al createShading() escrius que en el cas que el shading sigui NORMAL --> s= make_shared<NormalShading>();
al getShadingType() escrius: else if (name == "NORMAL") return SHADING_TYPES::NORMAL;
al getNameType()  escrius que en el cas queel shading sigui NORMAL retori un QString amb "NORMAL"
al getIndexType() en el cas que (dynamic_pointer_cast<NormalShading>(m) != nullptr) fas un return SHADING_TYPES::NORMAL;
al switchShading() en el cas que no hi hagi ombres i (dynamic_pointer_cast<NormalShading>(m) != nullptr) fas que m_out = createShading(NORMAL);

        * 3j. Canvia ara per a que l’esfera es vegi segons una nova estratègia, usant el valor de la seva distància a l’observador. Com aconsegueixes que els colors estiguin normalitzats? Fixa’t on tens situada la càmera i on està situada l’esfera a la teva escena. Pots provar diferents gradacions.
            * Els colors es normalitzen utilitzant la distància entre el punt d'intersecció i el punt de visualització (lookFrom), i la distància màxima de renderització. Això es fa a través del càlcul de la distància normalitzada, que es calcula dividint la distància real entre la distància màxima. Després s'assigna el valor de la distància normalitzada a cada canal de color RGB, creant un vector de color gris que va del negre (distància mínima) al blanc (distància màxima).
            
        * 3n. Prova a carregar ara el fitxer de dades reals data0.json que conté en l’array de data amb un puntsituat a -2, -1 del món real i mostreja el valor de 0.5. Manté el mateix fitxer de setup de la visualització que has usat en el punt anterior. Per què veus només una esfera? On està situada a la teva escena? Amb quin radi? Per què? Per què és lila i no de color "kd": [0.7,0.6,0.5] com posa el fitxer? Ressegueix amb el debugger la creació de l’escena en aquest cas on el fitxer conté dades.
        
            * Només veiem una esfera a l'escena perquè només hi ha un atribut en el fitxer data0.json que representa una esfera. L'esfera està situada al món virtual, entre les coordenades (-5, 0, -5) i (5, 2.0, 5) amb un radi de 1 unitat. L'esfera és de color lila perquè s'especifica en l'atribut "colorMap" que s'utilitzi el mapa de colors "COLOR_MAP_TYPE_INFERNO". Aquest mapa de colors assigna diferents colors a diferents valors, i en aquest cas, assigna el color lila al valor 0.5. La propietat "kd" especifica el color de difusió, que en aquest cas és [0.7, 0.6, 0.5], però això no afecta el color final de l'esfera.
            
    * FASE 1
        * 3a. Quan penses que és millor crear els triangles de la malla?
            * Per aconseguir crear els triangles adequats per la creació de la malla, la funció maketriangles() s'haurà de cridar seguidament d'haver llegit el fitxer amb load(), així, un cop ja tenim la informació d'arestes i vertex, podem começar a generar els triangles en bucle.
            
        * 3b. Quina creus que teòricament és millor? Com funcionen en la realitat?
            * Una bounding sphere és una esfera que envolta un objecte 3D. Aquesta esfera es calcula a partir dels punts extrems de l'objecte, i té un radi que permet determinar la distància màxima entre el centre de l'esfera i qualsevol punt de l'objecte. De forma similar, una bounding box és un cub que envolta un objecte 3D i al igual que la bounding box ens ajuda a fer molt més eficaç un sistema de col·lisions. Quina és millor? En resum, depén del objecte 3D. La bounding sphere és millor utilitzada en situacions on els objectes són esfèrics o quasi-esfèrics, ja que ofereix una representació més senzilla i fàcil de calcular per a la detecció de col·lisions. D'altra banda, la bounding box és més eficaç en situacions on els objectes són rectangulars, ja que ofereix una representació més precisa de l'espai ocupat per l'objecte. En molts casos, es pot utilitzar una combinació de les dues tècniques per obtenir una detecció de col·lisions més precisa i eficient en escenes 3D complexes.
            
    * FASE 2
        * 1.2. On afegiries un atribut numSamples que defineixi el nombre de rajos per píxel i així controlar aquest fet?
            * Aquest atribut es definirà a la classe Setup.hh
            
        * 1.3. Es tracta de fer l'arrel quadrada de cada canal del color just abans de pintar-lo. On faràs aquesta correcció?
            * La correcció Gamma l'aplicarem al final del procés de renderització, abans que la imatge sigui mostrada a l'usuari. Això vol dir que la correcció es farà després de calcular els colors finals de tots els objectes en l'escena, i abans de mostrar la imatge acabada.
            
        * 2.3. Què necessites canviar? 
            * Per implementar Phong Shading a partir de Blinn-Phong Shading, haurem de canviar la fórmula de la reflexió especular. La resta romandrà com en el càlcul inicial.
            
        * 2.4. Necessites afegir informació en el material?
            * No hem hagut d'afegir informació en el material, simplement hem hagut de redefinir el mètode shading() per a passar una variable extra per paràmetre.
            
        * 3.2. En el cas que hi hagi un objecte entre la llum i el punt on s'està calculant la il·luminació, quina component de la fórmula de Blinn-Phong s'haurà de tenir en compte?
            * Les components difosa i especular de la fórmula de Blinn-Phong depenen de la posició de la llum i la posició de l'observador respecte a la superfície il·luminada, però no depenen de l'existència d'un objecte entre la llum i el punt d'observació. Per tant, en el cas que hi hagi un objecte entre la llum i el punt on s'està calculant la il·luminació, només s'haurà de tenir en compte la component ambient de la fórmula de Blinn-Phong.
            
        * 4.3. Per què si tens el MAX_DEPTH a 1, l’esfera no es veu transparent?
            * Si hi ha materials transparents a l'escena, com ara vidres o superfícies d'aigua, aquests materials requereixen que els raigs es reflecteixin i refractin a través de la seva superfície per reproduir adequadament el seu aspecte visual. Però si la profunditat de seguiment de raigs està limitada a 1, els raigs que travessen aquests materials transparents no tindran suficient profunditat per calcular correctament la seva trajectòria, i per tant, aquests materials transparents no es mostraran correctament a la pantalla.
            
        * 4.3. Si assignes el color ambient global enlloc del de background en els rajos secundaris que no intersequen amb res. Com et canvia la visualització? Raona el per què?
            * Assignar el color ambient global en lloc del color de fons en els raigs secundaris que no intersequen amb cap objecte tindria com a conseqüència que aquests raigs que no intercepten cap objecte, tindrien un color ambient uniforme en lloc d'un color de fons o background. Això podria canviar la visualització, depenent de l'escena en qüestió.
            
         * 5.1 Com faries el càlcul de les penombres?
Per incloure penombres en la visualització, utilitzant llums amb àrea o simplificacions que permetin calcular penombres aproximades, podem utilitzar la tècnica de "soft shadows" (ombres suaus). Les ombres suaus són ombres que no tenen un límit dur entre la llum i l'ombra, sinó que es difuminen gradualment, el que produeix una aparença més realista.
Una forma d'aconseguir això és utilitzar "penombres per mostra" (shadow sampling), que implica calcular múltiples mostres de llum per a cada punt d'intersecció. En lloc d'utilitzar una sola font de llum puntual, es pot modelar la font de llum com un àrea i calcular les mostres de llum des de diferents punts dins d'aquesta àrea. Això farà que les ombres siguin més suaus i realistes.

    * FASE 3
        * Qui calcularà les coordenades (u, v) del punt d’intersecció amb el pla?
            * Per calcular les coordenades (u, v) del punt d'intersecció amb el pla, caldria fer el següent:
                1. Trobar la intersecció del raig amb el pla base. Per fer-ho, caldria resoldre l'equació del pla i del raig, i trobar el punt d'intersecció (P).
                2. Calcular les coordenades (u, v) d'aquest punt d'intersecció. Es podria fer projectant el punt P al pla base i calculant les coordenades relatives a la textura. Per fer-ho, es pot utilitzar la base ortonormal del pla i les dimensions de la textura. Per exemple, si el pla base està alineat amb l'eix X i Y, les coordenades (u, v) es podrien calcular com:
            ```cpp
            u = (P.x - xmin) / (xmax - xmin)
            v = (P.y - ymin) / (ymax - ymin)
            ```

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
    
- Més exemples de metal + rajos reflectits (maxdepth=1, maxdepth=3, maxdepth=10):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228989240-41c99af6-10ed-48c6-85cc-79e7788d9945.png" alt="Metal (maxdepth=1)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989243-a311ecf7-37ca-4c39-b46e-77e8af0e9719.png" alt="Metal (maxdepth=3)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989247-b7edc905-ce50-4ed5-ba23-ad27eba01fe0.png" alt="Metal (maxdepth=10)" width="25%">
    </p>
    
- Altres tipus de shading per veure d'altres efectes en les reflexions (color shading, normal shading, phong shading, cell shading; maxdepth=10):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/227645090-752debc8-d239-4621-8658-00e1121e8796.png" alt="Color metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645209-a3ed8a19-c759-4f90-9deb-9b98ca02b485.png" alt="Normal metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645265-de776caf-9527-4afe-98f6-06df052c173d.png" alt="Phong metal (maxdepth=10)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/227645338-cf974249-bd48-4979-9e2e-3e99f89456d3.png" alt="Cell metal (maxdepth=10)" width="25%">
    </p>
    
- Material transparent + rajos reflectits (maxdepth=1, maxdepth=2, maxdepth=3):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228989391-9c625898-45e1-4deb-91c8-3cf9cd22f917.png" alt="Transparent (maxdepth=1)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989394-9462a19b-d241-4006-b7ee-025b5c7bb64e.png" alt="Transparent (maxdepth=2)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989398-f49f9c2f-646f-4945-aea5-43623274aad2.png" alt="Transparent (maxdepth=3)" width="25%">
    </p>
    
- Material transparent des d'un altre punt de vista:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228989530-7333e643-fdf6-43a0-83bc-73552a8b136c.png" alt="Transparent other view" width="45%">
    </p>

- Material transparent (four spheres) (maxdepth=1, maxdepth=2, maxdepth=4):
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228989756-a213c047-6543-4cc5-9e60-65da6c60c2d3.png" alt="Four Transparent (maxdepth=1)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989764-c5b3773d-4971-441b-9c63-20108be3362c.png" alt="Four Transparent (maxdepth=2)" width="25%">
    <img src="https://user-images.githubusercontent.com/47271218/228989774-d177d34f-65a6-4b41-92fa-daa46453cc50.png" alt="Four Transparent (maxdepth=4)" width="25%">
    </p>
    

Pas 5. Visualization Mapping:
    
- Diferents escenes i fitxers:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990036-15795a7e-f8b4-47dc-97c9-c885bf3522b6.png" alt="Visualization Mapping 1" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990156-b72345e2-7e5c-4c4d-961e-6870882c0bbf.png" alt="Visualization Mapping 2" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990230-aea55a44-6bf1-4ecf-b627-e83923367061.png" alt="Visualization Mapping 3" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990261-9a60f88a-1b2e-4007-9619-6429e1cdf16f.png" alt="Visualization Mapping 4" width="45%">
    </p>

    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990353-a7d9e298-0629-4903-9861-8dd022fc0dc7.png" alt="Visualization Mapping 5" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990473-65437b76-83df-42a8-8a19-c361c898abc5.png" alt="Visualization Mapping 6" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990491-189e9f98-0716-4246-9e8e-26e2014cfbf9.png" alt="Visualization Mapping 7" width="45%">
    </p>
 
- Fent servir una paleta de colors diferent:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228990583-5a47622c-2e0c-4833-9b30-460d5b9a7505.png" alt="Visualization Mapping 8" width="45%">
    </p>
    
* **Fase 3**: 
- Pas 1. Afegeix un nou material:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228991154-b1de2734-20dd-4d63-86a9-c706c05631cd.png" alt="Nou material 1" width="45%">
    </p>

    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228991235-1df6b9f4-62d0-4627-83e7-287539c10b05.png" alt="Nou material 2" width="45%">
    </p>
   
- Pas 2. Prova amb diferents jocs de dades i mapes:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228991320-6b93c8ac-3dfc-438a-8cde-16ceeaf39c26.png" alt="Diferents jocs de dades i mapes 1" width="45%">
    </p>
    
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228991373-8af66ed4-7eda-46ce-81de-912e864d4144.png" alt="Diferents jocs de dades i mapes 2" width="45%">
    </p>

- Pas 3. Genera diferents jocs de dades i mapes:
    <p align="center">
    <img src="https://user-images.githubusercontent.com/47271218/228991738-6c83e58d-9c08-4f57-9560-bd971ab94105.png" alt="Mapa Murcia" width="45%">
    </p>
    
* **Més visualitzacions**:



   * Per totes les imatges, incluiu aqui la imatge obtinguda i els fitxers de dades i de configuració que heu fet servir
