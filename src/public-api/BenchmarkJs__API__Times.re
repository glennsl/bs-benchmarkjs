module type Intf = {
  type t;
  let getCycle: t => float;
  let getElapsed: t => float;
  let getPeriod: t => float;
  let getTimeStamp: t => float;
};

module Impl: (T: {type t;}) => Intf =
  (T: {type t;}) => {
    module Internal =
      BenchmarkJs__FFI.Times.Impl({
        type t = T.t;
      });
    type t = T.t;
    let getCycle: T.t => float = Internal.getCycle;
    let getElapsed: T.t => float = Internal.getElapsed;
    let getPeriod: T.t => float = Internal.getPeriod;
    let getTimeStamp: T.t => float = Internal.getTimeStamp;
  };