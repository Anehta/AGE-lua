
function path(a)
  if AGetSystemId() == 1 then
    --APrint("runing windows");
    local first = "./";
    return (string.format("%s%s",first,a));
  end
  
  if AGetSystemId() == 2 then
    --APrint("runing android_external_storage");
    local first = "/storage/emulated/0/";
    return (string.format("%s%s",first,a));
  end
  
  if AGetSystemId() == 3 then
    --APrint("runing android_built_in");
    local first = "/sdcard/";
    return (string.format("%s%s",first,a));
  end
  
    if AGetSystemId() == 4 then
    --APrint("runing android_built_in");
    local first = "/mnt/sdcard/";
    return (string.format("%s%s",first,a));
  end
  
  
  if AGetSystemId() == 5 then
   -- APrint("runing IOS");
  end
  
  if AGetSystemId() == 6 then
    --APrint("runing MAC");
  end
  
  if AGetSystemId() == 7 then
    --APrint("runing Linux");
  end
end