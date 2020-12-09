- The bellman equation

- V(s) = maxa(R(s,a)+yV(s'))


- MDP (Markov decision process)

  - deterministic search

  - non deterministic search
    - It is to make a more realistic model of what could actually happen in a real world in a real world type of problem
    - Something that is out of the control of the agents is something I can't predict.


- A stochastic process has the Markov property if the conditional probability distribution of future states of the process (conditional on both past and present states) depends only upon the present state, not on the sequence of events that proceded it. A process with this property is called Markov process.
  - What matters is which state is he is now and so the probabilities of going left or right orup they will always be the same if he is in this state now. It doesn't matter what happened before.

- Markov decision processes (MDPs) provide a mathematical framework for modeling decision making in situations where outcomes are partly random and partly under the control of a decision maker.

- V(s) = maxa(R(s,a)+y sigma P(s,a,s')V(s')) 
