
module Impl = (T: { type t; }) => {

};

type t

include Impl({ type nonrec t = t; });
