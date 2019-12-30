module Impl =
       (
         T: {
           type t;
           type benchmark;
           type eventType;
           let encodeEventType: eventType => string;
           let decodeEventType: string => eventType;
         },
       ) => {
  module Internal = {
    include BenchmarkJs__FFI.Event.Impl({
      type t = T.t;
      type benchmark = T.benchmark;
    });
  };
  type eventType = T.eventType;
  let encodeEventType = T.encodeEventType;
  let decodeEventType = T.decodeEventType;
  let make: eventType => T.t = name => Internal.(make(encodeEventType(name)));
  let fromEvent: T.t => T.t = Internal.fromEvent;
  let isAborted: T.t => bool = Internal.getAborted;
  let isCancelled: T.t => bool = Internal.getCancelled;
  let currentTarget: T.t => T.benchmark = Internal.getCurrentTarget;
  let target: T.t => T.benchmark = Internal.getTarget;
  let timeStamp: T.t => int = Internal.getTimeStamp;
};

type t = BenchmarkJs__Types.event;

include Impl({
  type nonrec t = t;
  type benchmark = BenchmarkJs__Types.benchmark;
  type eventType = BenchmarkJs__Types.eventType;
  let encodeEventType = BenchmarkJs__Types.encodeEventType;
  let decodeEventType = BenchmarkJs__Types.decodeEventType;
});