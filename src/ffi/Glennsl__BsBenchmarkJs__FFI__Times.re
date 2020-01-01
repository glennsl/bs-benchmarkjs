module Impl = (T: {type t;}) => {
  [@bs.get] external getCycle: T.t => float = "cycle";
  [@bs.get] external getElapsed: T.t => float = "elapsed";
  [@bs.get] external getPeriod: T.t => float = "period";
  [@bs.get] external getTimeStamp: T.t => float = "timeStamp";
};