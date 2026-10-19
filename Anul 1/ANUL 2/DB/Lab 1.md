|Relație|Tip|Cum e implementată|
|---|---|---|
|`SpaceAgency` ↔ `Scientist`|**M:N**|`SpaceAgency_Scientist`|
|`SpaceAgency` → `ResearchCenter`|**1:N**|`ResearchCenter.agency_id`|
|`Mission` → `Robot`|**1:N**|`Robot.mission_id`|
|`Robot` ↔ `Planet`|**1:1**|`Robot.planet_id UNIQUE`|
|`Robot` ↔ `Sensor`|**M:N**|`Robot_Sensor`|
|`Robot` ↔ `Component`|**M:N**|`Robot_Component`|
|`Mission` → `Engineer`|**1:N**|`Engineer.mission_id`|
|`Engineer` ↔ `SpaceAgency`|**M:N**|`Engineer_SpaceAgency`|
|`Mission` ↔ `Scientist`|**M:N**|`Mission_Scientist`|
|`Robot` ↔ `Experiment`|**M:N**|`Robot_Experiment`|