module Impl = (T: {
                 type t;
                 type benchmark;
               }) => {
  module Internal =
    Glennsl__BsBenchmarkJs__FFI.Deferred.Impl({
      type t = T.t;
      type benchmark = T.benchmark;
    });
  let getBenchmark: T.t => T.benchmark = Internal.getBenchmark;
  let getCycle: T.t => float = Internal.getCycle;
  let getElapsed: T.t => float = Internal.getElapsed;
  let getTimeStamp: T.t => float = Internal.getTimeStamp;
};

include Impl({
  include Types;
  type t = deferred;
});