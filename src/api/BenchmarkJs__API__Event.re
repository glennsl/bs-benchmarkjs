module Impl =
       (
         T: {
           type t;
           type benchmark;
           type eventType;
           let eventTypeToString: eventType => string;
           let eventTypeFromString: string => eventType;
         },
       ) => {
  module Internal = {
    include BenchmarkJs__FFI.Event.Impl({
      type t = T.t;
      type benchmark = T.benchmark;
    });
  };
  type eventType = T.eventType;
  let eventTypeToString = T.eventTypeToString;
  let eventTypeFromString = T.eventTypeFromString;
  let make: eventType => T.t = name => Internal.(make(eventTypeToString(name)));
  let fromEvent: T.t => T.t = Internal.fromEvent;
  let isAborted: T.t => bool = Internal.getAborted;
  let isCancelled: T.t => bool = Internal.getCancelled;
  let currentTarget: T.t => T.benchmark = Internal.getCurrentTarget;
  let target: T.t => T.benchmark = Internal.getTarget;
  let timeStamp: T.t => int = Internal.getTimeStamp;
};