var addon = require('bindings')('pgg');
var Pgg = addon.Pgg;
var obj = new Pgg();

describe('Pgg', function(){
  it('is real', function(done){
    (typeof obj == 'object').should.be.true;
    (obj instanceof Pgg).should.be.true;
    done();
  });

  it ('has version 1.5.x', function(done){
    (typeof obj.version()).should.be.equal('string');
    /1.5/.test(obj.version()).should.be.true;
    done();
  });

  it ('shows engine info', function(done){
    (Array.isArray(obj.engineInfo())).should.be.true;
    obj.engineInfo().length.should.be.above(0);
    done();
  });
});
