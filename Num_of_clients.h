#pragma once

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для Num_of_clients
	/// </summary>
	public ref class Num_of_clients : public System::Windows::Forms::Form
	{
	public:
		Num_of_clients(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			saveFileDialog1->Filter = "Монохромный рисунок (*.bmp)|*.bmp|All files(*.*)|*.*";
			saveFileDialog1->DefaultExt = ".bmp";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Num_of_clients()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  Reload_diagram;
	private: System::Windows::Forms::Button^  exit;
	public: Form^ general;
	private: System::Windows::Forms::Button^  save;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	public:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Num_of_clients::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Reload_diagram = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->save = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 72);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Количество клиентов за месяц";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(935, 370);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"MM.yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(28, 31);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(25, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите месяц:";
			// 
			// Reload_diagram
			// 
			this->Reload_diagram->Location = System::Drawing::Point(254, 31);
			this->Reload_diagram->Name = L"Reload_diagram";
			this->Reload_diagram->Size = System::Drawing::Size(131, 21);
			this->Reload_diagram->TabIndex = 3;
			this->Reload_diagram->Text = L"Построить диаграмму";
			this->Reload_diagram->UseVisualStyleBackColor = true;
			this->Reload_diagram->Click += gcnew System::EventHandler(this, &Num_of_clients::Reload_diagram_Click);
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(872, 462);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 4;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &Num_of_clients::exit_Click);
			// 
			// save
			// 
			this->save->Location = System::Drawing::Point(446, 31);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(140, 20);
			this->save->TabIndex = 5;
			this->save->Text = L"Сохранить диаграмму";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &Num_of_clients::save_Click);
			// 
			// Num_of_clients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(959, 497);
			this->Controls->Add(this->save);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Reload_diagram);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->chart1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Num_of_clients";
			this->Text = L"Количество клиентов за месяц";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Num_of_clients::Num_of_clients_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void Num_of_clients_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	general->Enabled = true;
}
private: System::Void Reload_diagram_Click(System::Object^  sender, System::EventArgs^  e) 
{	
	this->chart1->Series["Количество клиентов за месяц"]->Points->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT S_date, COUNT(ID_connection) FROM Seance WHERE DATEDIFF(MONTH,S_date, \'01." + 
		dateTimePicker1->Text + "\') = 0 GROUP BY S_date";
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	Generic::Dictionary<String^, int>^ conns = gcnew Generic::Dictionary<String^, int>();
	while (dr->Read())
	{
		conns->Add(dr[0]->ToString(), Convert::ToInt32(dr[1]));
	}
	dr->Close();
	connect->Close();
	System::DateTime day = Convert::ToDateTime("01." + dateTimePicker1->Text->ToString());
	while (day.Month == Convert::ToDateTime("01." + dateTimePicker1->Text->ToString()).Month)
	{
		String^ day_string = day.ToString("dd.MM.yyyy") + " 0:00:00";
		if (conns->ContainsKey(day_string))
		{
			this->chart1->Series["Количество клиентов за месяц"]->Points->AddXY(day.ToString("dd.MM.yyyy"), conns[day_string]);
		}
		else
		{
			this->chart1->Series["Количество клиентов за месяц"]->Points->AddXY(day.ToString("dd.MM.yyyy"), int(0));
		}
		day = day.AddDays(1);
	}
	dr->Close();
	connect->Close();
}
private: System::Void save_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult(1))
	{
		chart1->SaveImage((saveFileDialog1->FileName), System::Drawing::Imaging::ImageFormat::Bmp);
	}
}
};
}
