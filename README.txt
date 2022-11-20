==== Mimosa Game Engine ====
  
  -- Functionality --
    
    * 2D/3D drawing capability (Polygon/Mesh - With optional textures.)
    * Object heirarchy (Child pos/rot is applied within the parent's coordinate space.)
    * Entity Component System
    * 2D/3D physics engine (Available joints: Rotation, Linear, Spring, Flex)
    * Custom scripting language (Named MimSL, can call provided engine functions,
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
    associated with a System. Components always
    have a name, and can be found using it.
    Custom Components can be created using [UNDECIDED]
    
    - Systems -
    
    Can either be native C++ code or a MimSL
    script. A System "acts on" all Entities with
    a specific Component or combination of
    Components. For example, a Rendering System
    could "act on" all Entities with a Renderer
    Component and a Material Component.
    
    What is meant by "act(s) on" is that each Component
    can trigger Events that call Callbacks in the System.

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

  -- Events --
    
    An Event can be triggered by either the game engine
    itself (such as Init or Update events) or certain
    criteria being met on a Component.
    
    When an Event is triggered, it is scheduled to be
    handled by the Event Handler. If the Event Handler's
    queue is filled to 16, lower priority Events are dropped
    for higher priority ones.
    
    This means that if a Rendering
    Event came in while the queue was filled with Callback Events,
    the Rendering Event would be dropped, as losing a frame is less
    likely to break things than not calling a Callback.
  
  
  
  
  