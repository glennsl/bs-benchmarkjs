module Impl = (T: {
                 type t;
                 type benchmark;
               }) => {
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external make: string => T.t = "Event";
  [@bs.module "benchmark"] [@bs.scope "Benchmark"] [@bs.new] external fromEvent: T.t => T.t = "Event";
  // instance properties
  [@bs.get] external getAborted: T.t => bool = "aborted";
  [@bs.get] external getCancelled: T.t => bool = "cancelled";
  [@bs.get] external getCurrentTarget: T.t => T.benchmark = "currentTarget";
  [@bs.get] external getResult: T.t => 'a = "result";
  [@bs.get] external getTarget: T.t => T.benchmark = "target";
  [@bs.get] external getTimeStamp: T.t => int = "timeStamp";
  [@bs.get] external getType: T.t => string = "type";
};