module Impl = (T: {type t;}) => {
  module Internal =
    Glennsl__BsBenchmarkJs__FFI.Support.Impl({
      type t = T.t;
    });
  let browser: bool = Internal.(getBrowser(data));
  let decompilation: bool = Internal.(getDecompilation(data));
  let timeout: bool = Internal.(getTimeout(data));
};