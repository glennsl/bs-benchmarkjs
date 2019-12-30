module Obj = {

  let immutableUpdate = (~props, obj) => Js.Obj.(()->empty->assign(obj)->assign(props));
  
  let shallowCopy = [%bs.raw {|function(obj) {
      var _obj = {};
      var keys = Object.keys(obj);
      var length = keys.length;
      for (var i = 0; i < length; ++i) {
        var key = keys[i];
        _obj[key] = obj[key];
      };
      return _obj;
    }|}];

  let empty = [%bs.raw {|function() { return {}; }|}];

}