from scitools.std import *

class graph:

	def __init__(self, filname):
		self.filename = filename

		#self.plot_result()
		self.relative_error()

	def extract_data(self):
			 
		infile = open(self.filename, "r")
		lines = infile.readlines()
		
		output = []

		for line in lines:
			output.append(float(line))

		self.n = output[0]
		self.v = output[1:]
		self.v.append(0.0)
		self.v.insert(0, 0.0)
		self.x = linspace(0, 1, self.n)
		self.u = 1 - (1-exp(-10))*self.x - exp(-10*self.x)	

	def plot_result(self):		
		
		self.extract_data()
		
		plot(self.x, self.v)

		legend("Numerical solution")
		xlabel("x-values")
		ylabel("f(x)")
		hold("on")

		plot(self.x, self.u)

		legend("Analytical solution")
		title("Solution of the Poisson equation with n = %s" %self.n)

		raw_input("")
		
	def relative_error(self):
		
		import os
	
		log_h = []
		max_error = []		
		
		n_values = linspace(10, 10**5, 100)
		for N in n_values :
			n = int(N)
			os.system("g++ main.cpp")
			os.system("./a.out %d" % n)
			
			self.extract_data()	
			
			epsilon  = log10( abs((self.v[1 :-1] -self.u[1 :-1])/self.u[1 :-1]))
			max_error.append(max(epsilon))
			log_h.append(log10(1.0/(n+1.0)))
	
		error = array(max_error)
		h = array(log_h)
				
		plot(h, error)
		xlabel("log10(h)")
		ylabel("epsilon")
		title("Relative error")
		raw_input("")		
		
filename = "data.dat"
h = graph(filename)
