==== Mimosa Game Engine ====
  
  -- Functionality --
    
    * 2D/3D drawing capability (Polygon/Mesh - With optional textures.)
    * Object heirarchy (Child pos/rot is applied within the parent's coordinate space.)
    * Entity Component System
    * 2D/3D physics engine (Available joints: Rotation, Linear, Spring)
    * Custom scripting language (Named MimSL, can call provided game engine functions,
                                 functions in other MimSL scripts, and exported DLL
                                 functions.)
  
  -- 2D/3D Rendering --
    
    
  
  -- Entity Component System --
    
    - Entities -
    
    Implemented using a ID per Entity.
    Each entity can be found via:
    * Their ID (fast)
    * Their Transform component's Name field (slow)
    * Their Transform component's Tag field (slow)
    * Their position in the heirarchy (slow)
    
    - Components -
    
    Implemented using a UUID per Component.
    Each Component is either pure data, or
    associated with a System. Custom
    Components can be created using [UNDECIDED]
    
    - Systems -
    
    Can either be native C++ code or a MimSL
    script. A System acts on all Entities with
    a specific Component or combination of
    Components. For example, a Rendering System
    could act on all Entities with a MeshRenderer
    Component and a Material Component.
    
    Each MimSL Custom System has Callbacks that are called
    at specfic times during an Entity's lifetime.
    (Said Entity has to have the correct Components
     for the System.)
    Said Callbacks are:
    * Init (Called when the Entity is initialized)
    * Update (Called when a update occurs on the Entity)
    * PhysUpdate (Called when a physics update occurs on the Entity)
    
    Each System can also create its own Callbacks
    that can be called from its required Components.
  
  -- Custom Scripting Language (MimSL) --
  
  
  
  
  